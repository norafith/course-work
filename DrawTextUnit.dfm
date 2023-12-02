object DrawTextForm: TDrawTextForm
  Left = 0
  Top = 0
  Caption = #1056#1080#1089#1086#1074#1072#1085#1080#1077' '#1090#1077#1082#1089#1090#1072
  ClientHeight = 80
  ClientWidth = 403
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  DesignSize = (
    403
    80)
  TextHeight = 15
  object ConfigureFontButton: TButton
    Left = 8
    Top = 44
    Width = 387
    Height = 28
    Anchors = [akLeft, akRight, akBottom]
    Caption = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1096#1088#1080#1092#1090
    TabOrder = 0
    OnClick = ConfigureFontButtonClick
    ExplicitTop = 64
    ExplicitWidth = 356
  end
  object DrawTextEdit: TEdit
    Left = 8
    Top = 13
    Width = 387
    Height = 28
    Hint = #1042#1074#1077#1076#1080#1090#1077' '#1090#1077#1082#1089#1090'...'
    Anchors = [akLeft, akTop, akRight, akBottom]
    ImeName = 'DrawTextEdit'
    TabOrder = 1
    ExplicitWidth = 356
    ExplicitHeight = 23
  end
  object ConfigureFontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    Left = 360
    Top = 168
  end
  object DrawFontDialog: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    Left = 184
    Top = 16
  end
end
