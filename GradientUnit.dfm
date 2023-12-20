object GradientForm: TGradientForm
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1076#1080#1077#1085#1090
  ClientHeight = 402
  ClientWidth = 324
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
    324
    402)
  TextHeight = 15
  object GradientPreviewImage: TImage
    Left = 8
    Top = 24
    Width = 296
    Height = 153
    Anchors = [akLeft, akTop, akRight]
    ExplicitWidth = 307
  end
  object GradientToolsPanel: TPanel
    Left = 8
    Top = 192
    Width = 296
    Height = 202
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 0
    ExplicitWidth = 289
    ExplicitHeight = 183
    DesignSize = (
      296
      202)
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
    object SwitchColorsButton: TSpeedButton
      Left = 158
      Top = 24
      Width = 20
      Height = 20
      Glyph.Data = {
        52050000424D5205000000000000420000002800000012000000120000000100
        20000300000010050000C30E0000C30E000000000000000000000000FF0000FF
        0000FF000000000000000000006D000000CF000000130000000D0000005C0000
        00B5000000EB000000FF000000FF000000EC000000B70000005E000000100000
        00000000000000000000000000000000000000000081000000E5000000560000
        00B5000000F4000000D9000000A60000008700000086000000A4000000D70000
        00F4000000BA0000003A000000000000000000000000000000000000007F0000
        00FB000000ED000000D900000065000000180000000100000000000000000000
        00010000001900000066000000DC000000E50000005000000000000000000000
        00000000007F000000FF000000ED000000780000004600000023000000000000
        0000000000000000000000000000000000000000002C000000C5000000E50000
        003A000000000000000000000051000000ED000000F7000000F2000000F70000
        0097000000010000000000000000000000000000000000000000000000000000
        002B000000DC000000B9000000100000000000000005000000360000004A0000
        004A0000004A0000002500000000000000000000000000000000000000000000
        0000000000000000000000000066000000F40000005E00000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000019000000D8000000B70000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000010000
        00A6000000EF0000001300000008000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000069000000CA000000CA0000006900000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000800000013000000EF000000A70000
        0001000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00B7000000D80000001900000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000005E000000F4000000680000000000000000000000000000
        000000000000000000000000000000000000000000250000004A0000004A0000
        004A00000035000000050000000000000010000000B9000000DD0000002D0000
        0000000000000000000000000000000000000000000000000002000000970000
        00F7000000F2000000F7000000ED0000005000000000000000000000003A0000
        00E5000000C60000002D00000000000000000000000000000000000000000000
        0000000000230000004600000079000000ED000000FF0000007F000000000000
        00000000000000000050000000E5000000DD0000006800000019000000010000
        000000000000000000020000001800000065000000D9000000ED000000FB0000
        007F000000000000000000000000000000000000003A000000BA000000F50000
        00D8000000A50000008700000087000000A6000000D9000000F4000000B50000
        0056000000E50000008100000000000000000000000000000000000000000000
        00100000005F000000B7000000EC000000FF000000FF000000EC000000B60000
        005C0000000D00000013000000CF0000006D00000000}
      OnClick = SwitchColorsButtonClick
    end
    object StartColorPanel: TPanel
      Left = 192
      Top = 9
      Width = 97
      Height = 22
      Anchors = [akLeft, akTop, akRight]
      Color = clWhite
      ParentBackground = False
      TabOrder = 0
      ExplicitWidth = 96
      object StartColorButton: TSpeedButton
        Left = 1
        Top = 1
        Width = 95
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
      Left = 192
      Top = 38
      Width = 96
      Height = 20
      Anchors = [akLeft, akTop, akRight]
      Color = clWhite
      ParentBackground = False
      TabOrder = 1
      ExplicitWidth = 95
      object EndColorButton: TSpeedButton
        Left = 1
        Top = 1
        Width = 94
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
      Width = 279
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
      Top = 163
      Width = 70
      Height = 25
      Anchors = [akLeft, akTop, akRight]
      Caption = 'OK'
      TabOrder = 5
      OnClick = ApplyGradientButtonClick
      ExplicitWidth = 69
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
