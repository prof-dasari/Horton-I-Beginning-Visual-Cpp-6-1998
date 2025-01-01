VERSION 4.00
Begin VB.Form Form1 
   Caption         =   "TestRefRate"
   ClientHeight    =   3030
   ClientLeft      =   1260
   ClientTop       =   2730
   ClientWidth     =   6690
   Height          =   3435
   Left            =   1200
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   ScaleHeight     =   3030
   ScaleWidth      =   6690
   Top             =   2385
   Width           =   6810
   Begin VB.TextBox txtVRes 
      Height          =   375
      Left            =   4080
      Locked          =   -1  'True
      TabIndex        =   3
      Top             =   2400
      Width           =   2415
   End
   Begin VB.TextBox txtHRes 
      Height          =   375
      Left            =   4080
      Locked          =   -1  'True
      TabIndex        =   2
      Top             =   1800
      Width           =   2415
   End
   Begin VB.TextBox txtRRate 
      Height          =   375
      Left            =   4080
      Locked          =   -1  'True
      TabIndex        =   1
      Top             =   1200
      Width           =   2415
   End
   Begin VB.TextBox txtHScanMax 
      Height          =   375
      Left            =   4080
      TabIndex        =   0
      Top             =   600
      Width           =   2415
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      Caption         =   "Vertical Resolution (pixels)"
      Height          =   195
      Left            =   360
      TabIndex        =   8
      Top             =   2400
      Width           =   1845
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "Horizontal Resolution (pixels)"
      Height          =   195
      Left            =   360
      TabIndex        =   7
      Top             =   1800
      Width           =   2025
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "Refresh Rate (Hz)"
      Height          =   195
      Left            =   360
      TabIndex        =   6
      Top             =   1200
      Width           =   1275
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "Maximum Horizontal Scan Rate (kHz)"
      Height          =   195
      Left            =   360
      TabIndex        =   5
      Top             =   600
      Width           =   2640
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "Enter a value for the horizontal scan rate in kilohertz and press Enter."
      Height          =   195
      Left            =   720
      TabIndex        =   4
      Top             =   120
      Width           =   4860
   End
End
Attribute VB_Name = "Form1"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Private Sub txtHScanMax_KeyPress(KeyAscii As Integer)
    Dim objRefRate As New RefRate
    If (KeyAscii = 13) Then
       txtRRate.Text = objRefRate.RefreshRate(HScan:=Val(txtHScanMax.Text))
       txtHRes.Text = objRefRate.GetHRes
       txtVRes.Text = objRefRate.GetVRes
    End If
End Sub
