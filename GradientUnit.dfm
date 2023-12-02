object GradientForm: TGradientForm
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1076#1080#1077#1085#1090
  ClientHeight = 305
  ClientWidth = 323
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  DesignSize = (
    323
    305)
  TextHeight = 15
  object GradientPreviewImage: TImage
    Left = 8
    Top = 24
    Width = 301
    Height = 153
    Anchors = [akLeft, akTop, akRight]
    ExplicitWidth = 572
  end
  object GradientToolsPanel: TPanel
    Left = 8
    Top = 192
    Width = 301
    Height = 105
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    ExplicitWidth = 295
    ExplicitHeight = 96
    DesignSize = (
      301
      105)
    object Label1: TLabel
      Left = 16
      Top = 8
      Width = 139
      Height = 23
      Caption = #1053#1072#1095#1072#1083#1100#1085#1099#1081' '#1094#1074#1077#1090': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 37
      Width = 130
      Height = 23
      Caption = #1050#1086#1085#1077#1095#1085#1099#1081' '#1094#1074#1077#1090': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 66
      Width = 115
      Height = 23
      Caption = #1059#1075#1086#1083' '#1085#1072#1082#1083#1086#1085#1072': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object EndColorButton: TSpeedButton
      Left = 169
      Top = 36
      Width = 114
      Height = 22
      Anchors = [akLeft, akTop, akRight]
      DisabledImageName = 'EndColorButton'
      ExplicitWidth = 120
    end
    object GradientAngleEdit: TSpinEdit
      Left = 169
      Top = 64
      Width = 114
      Height = 24
      Anchors = [akLeft, akTop, akRight]
      MaxValue = 360
      MinValue = 0
      TabOrder = 0
      Value = 0
      ExplicitWidth = 108
    end
    object StartColorButton: TBitBtn
      Left = 169
      Top = 5
      Width = 114
      Height = 25
      DisabledImageName = 'StartColorButton'
      TabOrder = 1
      OnClick = StartColorButtonClick
    end
  end
  object StartColorDialog: TColorDialog
    OnClose = StartColorDialogClose
    OnShow = StartColorDialogShow
    Left = 152
    Top = 96
  end
  object EndColorDialog: TColorDialog
    OnClose = EndColorDialogClose
    OnShow = EndColorDialogShow
    Left = 232
    Top = 120
  end
end
