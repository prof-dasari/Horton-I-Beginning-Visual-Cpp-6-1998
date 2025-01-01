#if !defined(Elements_h)
#define Elements_h

class CElement : public CObject
{
protected:
   COLORREF m_Color;                          // Color of an element
   CRect m_EnclosingRect;                  // Rectangle enclosing an element
   int m_Pen;                              // Pen width

public:
   virtual ~CElement(){}                      // Virtual destructor

   // Virtual draw operation
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const {}
   virtual void Move(const CSize& Size) {}    // Move an element
   CRect GetBoundRect() const;                // Get the bounding rectangle for an element

protected:
   CElement(){}                               // Default constructor
};

// Class defining a line object
class CLine : public CElement
{
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;

   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a line object
   CLine(const CPoint& Start, const CPoint& End, const COLORREF& Color);

protected:
   CPoint m_StartPoint;          // Start point of line
   CPoint m_EndPoint;            // End point of line

   CLine(){}             // Default constructor - should not be used
};

// Class defining a rectangle object
class CRectangle : public CElement
{
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;

   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a rectangle object
   CRectangle(const CPoint& Start, const CPoint& End, const COLORREF& Color);

protected:
   CRectangle(){}        // Default constructor - should not be used
};

// Class defining a circle object
class CCircle : public CElement
{
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;

   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a circle object
   CCircle(const CPoint& Start, const CPoint& End, const COLORREF& Color);

protected:
   CCircle(){}           // Default constructor - should not be used
};

// Class defining a curve object
class CCurve : public CElement
{
public:
   // Function to display a line
   virtual void Draw(CDC* pDC, const CElement* pElement = 0) const;

   virtual void Move(const CSize& aSize);       // Function to move an element

   // Constructor for a curve object
   CCurve(const CPoint& FirstPoint, const CPoint& SecondPoint, const COLORREF& Color);

   void AddSegment(const CPoint& Point);     //Add a segment to the curve

protected:
   // CCurve data members to go here
   CList<CPoint, const CPoint&> m_PointList;  // Type safe point list

   CCurve(){}           // Default constructor - should not be used
};

#endif //!defined(Elements_h)
