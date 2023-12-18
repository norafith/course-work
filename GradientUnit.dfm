object GradientForm: TGradientForm
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1076#1080#1077#1085#1090
  ClientHeight = 392
  ClientWidth = 323
  Color = clBtnFace
  Constraints.MinHeight = 428
  Constraints.MinWidth = 323
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnResize = FormResize
  DesignSize = (
    323
    392)
  TextHeight = 15
  object GradientPreviewImage: TImage
    Left = 8
    Top = 24
    Width = 301
    Height = 153
    Anchors = [akLeft, akTop, akRight]
    ExplicitWidth = 307
  end
  object GradientToolsPanel: TPanel
    Left = 8
    Top = 192
    Width = 301
    Height = 192
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    ExplicitWidth = 295
    ExplicitHeight = 161
    DesignSize = (
      301
      192)
    object Label1: TLabel
      Left = 10
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
      Left = 10
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
    object StartColorPanel: TPanel
      Left = 169
      Top = 9
      Width = 125
      Height = 22
      Anchors = [akLeft, akTop, akRight]
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      object StartColorButton: TSpeedButton
        Left = 1
        Top = 1
        Width = 123
        Height = 20
        Align = alClient
        DisabledImageName = 'StartColorButton'
        Flat = True
        OnClick = StartColorButtonClick
        ExplicitTop = 17
        ExplicitWidth = 118
      end
    end
    object EndColorPanel: TPanel
      Left = 170
      Top = 38
      Width = 123
      Height = 20
      Anchors = [akLeft, akTop, akRight]
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      object EndColorButton: TSpeedButton
        Left = 1
        Top = 1
        Width = 121
        Height = 18
        Align = alClient
        Flat = True
        OnClick = EndColorButtonClick
        ExplicitWidth = 112
      end
    end
    object RadioGroup1: TRadioGroup
      Left = 10
      Top = 66
      Width = 284
      Height = 87
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 2
      ExplicitWidth = 278
    end
    object SelectHorizontalRadio: TRadioButton
      Left = 16
      Top = 80
      Width = 273
      Height = 25
      Caption = #1043#1086#1088#1080#1079#1086#1085#1090#1072#1083#1100#1085#1086#1077' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      TabStop = True
      OnClick = SelectHorizontalRadioClick
    end
    object SelectVerticalRadio: TRadioButton
      Left = 16
      Top = 111
      Width = 273
      Height = 25
      Caption = #1042#1077#1088#1090#1080#1082#1072#1083#1100#1085#1086#1077' '#1085#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = SelectVerticalRadioClick
    end
    object ApplyGradientButton: TButton
      Left = 219
      Top = 159
      Width = 75
      Height = 25
      Anchors = [akLeft, akTop, akRight]
      Caption = 'OK'
      TabOrder = 5
      OnClick = ApplyGradientButtonClick
    end
  end
  object StartColorDialog: TColorDialog
    OnShow = StartColorDialogShow
    Left = 152
    Top = 96
  end
  object EndColorDialog: TColorDialog
    OnShow = EndColorDialogShow
    Left = 232
    Top = 120
  end
end
