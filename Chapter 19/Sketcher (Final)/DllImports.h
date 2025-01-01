// Variables defined in the shape DLL ExtDLLExample.dll
#if !defined(DllImports_h)
#define DllImports_h

#define DLLIMPORT __declspec( dllimport )

// Import element type declarations
// Each type value must be unique
DLLIMPORT extern const WORD LINE;
DLLIMPORT extern const WORD RECTANGLE;
DLLIMPORT extern const WORD CIRCLE;
DLLIMPORT extern const WORD CURVE;
DLLIMPORT extern const WORD TEXT;
///////////////////////////////////

// Import color values for drawing
DLLIMPORT extern const COLORREF BLACK;
DLLIMPORT extern const COLORREF RED;
DLLIMPORT extern const COLORREF GREEN;
DLLIMPORT extern const COLORREF BLUE;
DLLIMPORT extern const COLORREF SELECT_COLOR;
///////////////////////////////////

// Plus the definitions for the element classes...

class AFX_EXT_CLASS CElement : public CObject
{
DECLARE_SERIAL(CElement)

protected:
   COLORREF m_Color;                       // Color of an element
   CRect m_EnclosingRect;                  // Rectangle enclosing an element
   int m_Pen;                              // Pen width

public:
   virtual ~CElement(){}                   // Virtual destructor

   // Virtual draw operation
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const {}
   virtual void Move(const CSize& Size) {} // Move an element
   CRect GetBoundRect() const;             // Get the bounding rectangle for an element

   virtual void Serialize(CArchive& ar);      // Serialize function for CElement

protected:
   CElement(){}                            // Default constructor
};

// Class defining a line object
class AFX_EXT_CLASS CLine : public CElement
{
DECLARE_SERIAL(CLine)

public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a line object
   CLine(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);

   virtual void Serialize(CArchive& ar);      // Serialize function for CLine

protected:
   CPoint m_StartPoint;          // Start point of line
   CPoint m_EndPoint;            // End point of line

   CLine(){}             // Default constructor - should not be used
};

// Class defining a rectangle object
class AFX_EXT_CLASS CRectangle : public CElement
{
DECLARE_SERIAL(CRectangle)

public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a rectangle object
   CRectangle(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);

   virtual void Serialize(CArchive& ar);      // Serialize function for CRectangle

protected:
   CRectangle(){}        // Default constructor - should not be used
};

// Class defining a circle object
class AFX_EXT_CLASS CCircle : public CElement
{
DECLARE_SERIAL(CCircle)

public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a circle object
   CCircle(const CPoint& Start, const CPoint& End, const COLORREF& Color, const int& PenWidth);

   virtual void Serialize(CArchive& ar);      // Serialize function for CCircle

protected:
   CCircle(){}           // Default constructor - should not be used
};

// Class defining a curve object
class AFX_EXT_CLASS CCurve : public CElement
{
DECLARE_SERIAL(CCurve)

public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;
   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a curve object
   CCurve(const CPoint& FirstPoint, const CPoint& SecondPoint, const COLORREF& Color, const int& PenWidth);

   virtual void Serialize(CArchive& ar);      // Serialize function for CCurve

   void AddSegment(const CPoint& Point);     //Add a segment to the curve

protected:
   // CCurve data members to go here
   CList<CPoint, const CPoint&> m_PointList;  // Type safe point list

   CCurve(){}           // Default constructor - should not be used
};

class AFX_EXT_CLASS CText : public CElement
{
DECLARE_SERIAL(CText)

public:
   // Function to display a text element
   virtual void Draw(CDC* pDC, const CElement* pElement = NULL) const;

   // Constructor for a text element
   CText(const CPoint& Start, const CPoint& End, const CString& String, const COLORREF& Color);
   virtual void Move(const CSize& Size);       // Move a text element

   virtual void Serialize(CArchive& ar);      // Serialize function for CText

protected:
   CPoint m_StartPoint;                   // position of a text element
   CString m_String;                      // Text to be displayed
   CText(){}                              // Default constructor
};

#endif // !defined(DllImports_h)

