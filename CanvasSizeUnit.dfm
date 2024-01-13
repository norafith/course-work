object CanvasSizeForm: TCanvasSizeForm
  Left = 0
  Top = 0
  Caption = #1061#1086#1083#1089#1090
  ClientHeight = 131
  ClientWidth = 222
  Color = clBtnFace
  Constraints.MaxHeight = 200
  Constraints.MaxWidth = 500
  Constraints.MinHeight = 178
  Constraints.MinWidth = 240
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  DesignSize = (
    222
    131)
  TextHeight = 15
  object WidthLabel: TLabel
    Left = 10
    Top = 11
    Width = 69
    Height = 23
    Caption = #1064#1080#1088#1080#1085#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object HeightLabel: TLabel
    Left = 10
    Top = 50
    Width = 60
    Height = 23
    Caption = #1042#1099#1089#1086#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object WidthEdit: TEdit
    Left = 90
    Top = 8
    Width = 100
    Height = 31
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 0
    OnKeyPress = WidthEditKeyPress
    ExplicitWidth = 106
  end
  object HeightEdit: TEdit
    Left = 90
    Top = 50
    Width = 100
    Height = 31
    Anchors = [akLeft, akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    NumbersOnly = True
    ParentFont = False
    TabOrder = 1
    OnKeyPress = HeightEditKeyPress
    ExplicitWidth = 106
  end
  object SetCanvasSizeButton: TButton
    Left = 144
    Top = 82
    Width = 44
    Height = 35
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'OK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = SetCanvasSizeButtonClick
    ExplicitWidth = 50
  end
end
