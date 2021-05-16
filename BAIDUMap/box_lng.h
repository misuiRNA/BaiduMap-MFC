#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CBox_lng 包装类

class CBox_lng : public CWnd
{
protected:
    DECLARE_DYNCREATE(CBox_lng)
public:
    CLSID const& GetClsid()
    {
        static CLSID const clsid
            = { 0x8BD21D10, 0xEC42, 0x11CE, { 0x9E, 0xD, 0x0, 0xAA, 0x0, 0x60, 0x2, 0xF3 } };
        return clsid;
    }
    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
                        const RECT& rect, CWnd* pParentWnd, UINT nID, 
                        CCreateContext* pContext = NULL)
    { 
        return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
    }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
                UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
                BSTR bstrLicKey = NULL)
    { 
        return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
        pPersist, bStorage, bstrLicKey); 
    }

// 特性
public:
enum
{
    fmDropEffectNone = 0,
    fmDropEffectCopy = 1,
    fmDropEffectMove = 2,
    fmDropEffectCopyOrMove = 3
}fmDropEffect;
enum
{
    fmActionCut = 0,
    fmActionCopy = 1,
    fmActionPaste = 2,
    fmActionDragDrop = 3
}fmAction;
enum
{
    fmModeInherit = -2,
    fmModeOn = -1,
    fmModeOff = 0
}fmMode;
enum
{
    fmMousePointerDefault = 0,
    fmMousePointerArrow = 1,
    fmMousePointerCross = 2,
    fmMousePointerIBeam = 3,
    fmMousePointerSizeNESW = 6,
    fmMousePointerSizeNS = 7,
    fmMousePointerSizeNWSE = 8,
    fmMousePointerSizeWE = 9,
    fmMousePointerUpArrow = 10,
    fmMousePointerHourGlass = 11,
    fmMousePointerNoDrop = 12,
    fmMousePointerAppStarting = 13,
    fmMousePointerHelp = 14,
    fmMousePointerSizeAll = 15,
    fmMousePointerCustom = 99
}fmMousePointer;
enum
{
    fmScrollBarsNone = 0,
    fmScrollBarsHorizontal = 1,
    fmScrollBarsVertical = 2,
    fmScrollBarsBoth = 3
}fmScrollBars;
enum
{
    fmScrollActionNoChange = 0,
    fmScrollActionLineUp = 1,
    fmScrollActionLineDown = 2,
    fmScrollActionPageUp = 3,
    fmScrollActionPageDown = 4,
    fmScrollActionBegin = 5,
    fmScrollActionEnd = 6,
    _fmScrollActionAbsoluteChange = 7,
    fmScrollActionPropertyChange = 8,
    fmScrollActionControlRequest = 9,
    fmScrollActionFocusRequest = 10
}fmScrollAction;
enum
{
    fmCycleAllForms = 0,
    fmCycleCurrentForm = 2
}fmCycle;
enum
{
    fmZOrderFront = 0,
    fmZOrderBack = 1
}fmZOrder;
enum
{
    fmBorderStyleNone = 0,
    fmBorderStyleSingle = 1
}fmBorderStyle;
enum
{
    fmTextAlignLeft = 1,
    fmTextAlignCenter = 2,
    fmTextAlignRight = 3
}fmTextAlign;
enum
{
    fmAlignmentLeft = 0,
    fmAlignmentRight = 1
}fmAlignment;
enum
{
    fmBordersNone = 0,
    fmBordersBox = 1,
    fmBordersLeft = 2,
    fmBordersTop = 3
}fmBorders;
enum
{
    fmBackStyleTransparent = 0,
    fmBackStyleOpaque = 1
}fmBackStyle;
enum
{
    fmButtonStylePushButton = 0,
    fmButtonStyleToggleButton = 1
}fmButtonStyle;
enum
{
    fmPicPositionCenter = 0,
    fmPicPositionTopLeft = 1,
    fmPicPositionTopCenter = 2,
    fmPicPositionTopRight = 3,
    fmPicPositionCenterLeft = 4,
    fmPicPositionCenterRight = 5,
    fmPicPositionBottomLeft = 6,
    fmPicPositionBottomCenter = 7,
    fmPicPositionBottomRight = 8
}fmPicPosition;
enum
{
    fmVerticalScrollBarSideRight = 0,
    fmVerticalScrollBarSideLeft = 1
}fmVerticalScrollBarSide;
enum
{
    fmLayoutEffectNone = 0,
    fmLayoutEffectInitiate = 1,
    _fmLayoutEffectRespond = 2
}fmLayoutEffect;
enum
{
    fmSpecialEffectFlat = 0,
    fmSpecialEffectRaised = 1,
    fmSpecialEffectSunken = 2,
    fmSpecialEffectEtched = 3,
    fmSpecialEffectBump = 6
}fmSpecialEffect;
enum
{
    fmDragStateEnter = 0,
    fmDragStateLeave = 1,
    fmDragStateOver = 2
}fmDragState;
enum
{
    fmPictureSizeModeClip = 0,
    fmPictureSizeModeStretch = 1,
    fmPictureSizeModeZoom = 3
}fmPictureSizeMode;
enum
{
    fmPictureAlignmentTopLeft = 0,
    fmPictureAlignmentTopRight = 1,
    fmPictureAlignmentCenter = 2,
    fmPictureAlignmentBottomLeft = 3,
    fmPictureAlignmentBottomRight = 4
}fmPictureAlignment;
enum
{
    fmButtonEffectFlat = 0,
    fmButtonEffectSunken = 2
}fmButtonEffect;
enum
{
    fmOrientationAuto = -1,
    fmOrientationVertical = 0,
    fmOrientationHorizontal = 1
}fmOrientation;
enum
{
    fmSnapPointTopLeft = 0,
    fmSnapPointTopCenter = 1,
    fmSnapPointTopRight = 2,
    fmSnapPointCenterLeft = 3,
    fmSnapPointCenter = 4,
    fmSnapPointCenterRight = 5,
    fmSnapPointBottomLeft = 6,
    fmSnapPointBottomCenter = 7,
    fmSnapPointBottomRight = 8
}fmSnapPoint;
enum
{
    fmPicturePositionLeftTop = 0,
    fmPicturePositionLeftCenter = 1,
    fmPicturePositionLeftBottom = 2,
    fmPicturePositionRightTop = 3,
    fmPicturePositionRightCenter = 4,
    fmPicturePositionRightBottom = 5,
    fmPicturePositionAboveLeft = 6,
    fmPicturePositionAboveCenter = 7,
    fmPicturePositionAboveRight = 8,
    fmPicturePositionBelowLeft = 9,
    fmPicturePositionBelowCenter = 10,
    fmPicturePositionBelowRight = 11,
    fmPicturePositionCenter = 12
}fmPicturePosition;
enum
{
    fmDisplayStyleText = 1,
    fmDisplayStyleList = 2,
    fmDisplayStyleCombo = 3,
    fmDisplayStyleCheckBox = 4,
    fmDisplayStyleOptionButton = 5,
    fmDisplayStyleToggle = 6,
    fmDisplayStyleDropList = 7
}fmDisplayStyle;
enum
{
    fmShowListWhenNever = 0,
    fmShowListWhenButton = 1,
    fmShowListWhenFocus = 2,
    fmShowListWhenAlways = 3
}fmShowListWhen;
enum
{
    fmShowDropButtonWhenNever = 0,
    fmShowDropButtonWhenFocus = 1,
    fmShowDropButtonWhenAlways = 2
}fmShowDropButtonWhen;
enum
{
    fmMultiSelectSingle = 0,
    fmMultiSelectMulti = 1,
    fmMultiSelectExtended = 2
}fmMultiSelect;
enum
{
    fmListStylePlain = 0,
    fmListStyleOption = 1
}fmListStyle;
enum
{
    fmEnterFieldBehaviorSelectAll = 0,
    fmEnterFieldBehaviorRecallSelection = 1
}fmEnterFieldBehavior;
enum
{
    fmDragBehaviorDisabled = 0,
    fmDragBehaviorEnabled = 1
}fmDragBehavior;
enum
{
    fmMatchEntryFirstLetter = 0,
    fmMatchEntryComplete = 1,
    fmMatchEntryNone = 2
}fmMatchEntry;
enum
{
    fmDropButtonStylePlain = 0,
    fmDropButtonStyleArrow = 1,
    fmDropButtonStyleEllipsis = 2,
    fmDropButtonStyleReduce = 3
}fmDropButtonStyle;
enum
{
    fmStyleDropDownCombo = 0,
    fmStyleDropDownList = 2
}fmStyle;
enum
{
    fmTabOrientationTop = 0,
    fmTabOrientationBottom = 1,
    fmTabOrientationLeft = 2,
    fmTabOrientationRight = 3
}fmTabOrientation;
enum
{
    fmTabStyleTabs = 0,
    fmTabStyleButtons = 1,
    fmTabStyleNone = 2
}fmTabStyle;
enum
{
    fmIMEModeNoControl = 0,
    fmIMEModeOn = 1,
    fmIMEModeOff = 2,
    fmIMEModeDisable = 3,
    fmIMEModeHiragana = 4,
    fmIMEModeKatakana = 5,
    fmIMEModeKatakanaHalf = 6,
    fmIMEModeAlphaFull = 7,
    fmIMEModeAlpha = 8,
    fmIMEModeHangulFull = 9,
    fmIMEModeHangul = 10,
    fmIMEModeHanziFull = 11,
    fmIMEModeHanzi = 12
}fmIMEMode;
enum
{
    fmTransitionEffectNone = 0,
    fmTransitionEffectCoverUp = 1,
    fmTransitionEffectCoverRightUp = 2,
    fmTransitionEffectCoverRight = 3,
    fmTransitionEffectCoverRightDown = 4,
    fmTransitionEffectCoverDown = 5,
    fmTransitionEffectCoverLeftDown = 6,
    fmTransitionEffectCoverLeft = 7,
    fmTransitionEffectCoverLeftUp = 8,
    fmTransitionEffectPushUp = 9,
    fmTransitionEffectPushRight = 10,
    fmTransitionEffectPushDown = 11,
    fmTransitionEffectPushLeft = 12
}fmTransitionEffect;
enum
{
    _fmListBoxStylesNone = 0,
    _fmListBoxStylesListBox = 1,
    _fmListBoxStylesComboBox = 2
}fmListBoxStyles;
enum
{
    _fmRepeatDirectionHorizontal = 0,
    _fmRepeatDirectionVertical = 1
}fmRepeatDirection;
enum
{
    _fmEnAutoSizeNone = 0,
    _fmEnAutoSizeHorizontal = 1,
    _fmEnAutoSizeVertical = 2,
    _fmEnAutoSizeBoth = 3
}fmEnAutoSize;


// 操作
public:

// IMdcText

// Functions
//

    void put_AutoSize(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(DISPID_AUTOSIZE, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_AutoSize()
    {
        BOOL result;
        InvokeHelper(DISPID_AUTOSIZE, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_AutoTab(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xd9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_AutoTab()
    {
        BOOL result;
        InvokeHelper(0xd9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_AutoWordSelect(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xda, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_AutoWordSelect()
    {
        BOOL result;
        InvokeHelper(0xda, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_BackColor(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_BackColor()
    {
        long result;
        InvokeHelper(DISPID_BACKCOLOR, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_BackStyle(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(DISPID_BACKSTYLE, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_BackStyle()
    {
        long result;
        InvokeHelper(DISPID_BACKSTYLE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_BorderColor(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(DISPID_BORDERCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_BorderColor()
    {
        long result;
        InvokeHelper(DISPID_BORDERCOLOR, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_BorderStyle(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(DISPID_BORDERSTYLE, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_BorderStyle()
    {
        long result;
        InvokeHelper(DISPID_BORDERSTYLE, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_BordersSuppress(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_BordersSuppress()
    {
        BOOL result;
        InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    BOOL get_CanPaste()
    {
        BOOL result;
        InvokeHelper(0x19, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_CurLine(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xd4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_CurLine()
    {
        long result;
        InvokeHelper(0xd4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    long get_CurTargetX()
    {
        long result;
        InvokeHelper(0xd2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    long get_CurTargetY()
    {
        long result;
        InvokeHelper(0xdd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_CurX(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xd0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_CurX()
    {
        long result;
        InvokeHelper(0xd0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_CurY(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xd1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_CurY()
    {
        long result;
        InvokeHelper(0xd1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_DropButtonStyle(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0x131, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_DropButtonStyle()
    {
        long result;
        InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_EnterKeyBehavior(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xfffffde0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_EnterKeyBehavior()
    {
        BOOL result;
        InvokeHelper(0xfffffde0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_Enabled(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_Enabled()
    {
        BOOL result;
        InvokeHelper(DISPID_ENABLED, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put__Font_Reserved(LPDISPATCH newValue)
    {
        static BYTE parms[] = VTS_DISPATCH ;
        InvokeHelper(0x7ffffdff, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    void putref_Font(LPDISPATCH newValue)
    {
        static BYTE parms[] = VTS_DISPATCH ;
        InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
    }
    LPDISPATCH get_Font()
    {
        LPDISPATCH result;
        InvokeHelper(DISPID_FONT, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
        return result;
    }
    void put_FontBold(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_FontBold()
    {
        BOOL result;
        InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_FontItalic(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_FontItalic()
    {
        BOOL result;
        InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_FontName(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    CString get_FontName()
    {
        CString result;
        InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_FontSize(CY newValue)
    {
        static BYTE parms[] = VTS_CY ;
        InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
    }
    CY get_FontSize()
    {
        CY result;
        InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_CY, (void*)&result, NULL);
        return result;
    }
    void put_FontStrikethru(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_FontStrikethru()
    {
        BOOL result;
        InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_FontUnderline(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_FontUnderline()
    {
        BOOL result;
        InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_FontWeight(short newValue)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    short get_FontWeight()
    {
        short result;
        InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, NULL);
        return result;
    }
    void put_ForeColor(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_ForeColor()
    {
        long result;
        InvokeHelper(DISPID_FORECOLOR, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_HideSelection(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xcf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_HideSelection()
    {
        BOOL result;
        InvokeHelper(0xcf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_IntegralHeight(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0x25c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_IntegralHeight()
    {
        BOOL result;
        InvokeHelper(0x25c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    long get_LineCount()
    {
        long result;
        InvokeHelper(0xd6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_Locked(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_Locked()
    {
        BOOL result;
        InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_MaxLength(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffdeb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_MaxLength()
    {
        long result;
        InvokeHelper(0xfffffdeb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_MouseIcon(LPDISPATCH newValue)
    {
        static BYTE parms[] = VTS_DISPATCH ;
        InvokeHelper(0xfffffdf6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    void putref_MouseIcon(LPDISPATCH newValue)
    {
        static BYTE parms[] = VTS_DISPATCH ;
        InvokeHelper(0xfffffdf6, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
    }
    LPDISPATCH get_MouseIcon()
    {
        LPDISPATCH result;
        InvokeHelper(0xfffffdf6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
        return result;
    }
    void put_MousePointer(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffdf7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_MousePointer()
    {
        long result;
        InvokeHelper(0xfffffdf7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_MultiLine(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xfffffde7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_MultiLine()
    {
        BOOL result;
        InvokeHelper(0xfffffde7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_PasswordChar(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xfffffdea, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    CString get_PasswordChar()
    {
        CString result;
        InvokeHelper(0xfffffdea, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_ScrollBars(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffde9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_ScrollBars()
    {
        long result;
        InvokeHelper(0xfffffde9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_SelectionMargin(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xdc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_SelectionMargin()
    {
        BOOL result;
        InvokeHelper(0xdc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_SelLength(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffddc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_SelLength()
    {
        long result;
        InvokeHelper(0xfffffddc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_SelStart(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffddd, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_SelStart()
    {
        long result;
        InvokeHelper(0xfffffddd, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_SelText(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xfffffdde, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    CString get_SelText()
    {
        CString result;
        InvokeHelper(0xfffffdde, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_ShowDropButtonWhen(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0x130, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_ShowDropButtonWhen()
    {
        long result;
        InvokeHelper(0x130, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_SpecialEffect(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_SpecialEffect()
    {
        long result;
        InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_TabKeyBehavior(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xfffffddf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_TabKeyBehavior()
    {
        BOOL result;
        InvokeHelper(0xfffffddf, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_Text(LPCTSTR newValue)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(DISPID_TEXT, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    CString get_Text()
    {
        CString result;
        InvokeHelper(DISPID_TEXT, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void put_TextAlign(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0x2714, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_TextAlign()
    {
        long result;
        InvokeHelper(0x2714, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    long get_TextLength()
    {
        long result;
        InvokeHelper(0xd8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    BOOL get_Valid()
    {
        BOOL result;
        InvokeHelper(0xfffffdf4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void put_Value(VARIANT * newValue)
    {
        static BYTE parms[] = VTS_PVARIANT ;
        InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    VARIANT get_Value()
    {
        VARIANT result;
        InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
        return result;
    }
    void put_WordWrap(BOOL newValue)
    {
        static BYTE parms[] = VTS_BOOL ;
        InvokeHelper(0xfffffde8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    BOOL get_WordWrap()
    {
        BOOL result;
        InvokeHelper(0xfffffde8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void Copy()
    {
        InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void Cut()
    {
        InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void Paste()
    {
        InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void put_IMEMode(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xfffffde2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_IMEMode()
    {
        long result;
        InvokeHelper(0xfffffde2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_EnterFieldBehavior(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xe0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_EnterFieldBehavior()
    {
        long result;
        InvokeHelper(0xe0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    void put_DragBehavior(long newValue)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0xe1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
    }
    long get_DragBehavior()
    {
        long result;
        InvokeHelper(0xe1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }
    long get_DisplayStyle()
    {
        long result;
        InvokeHelper(0xfffffde4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
        return result;
    }

// Properties
//



};
