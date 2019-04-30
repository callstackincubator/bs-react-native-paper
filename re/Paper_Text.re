[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~selectable: bool=?,
    ~acessible: bool=?,
    ~elipsizeMode: option(string)=?,
    ~nativeID: option(string)=?,
    ~numberOfLines: option(int)=?,
    ~pressRetentionOffset: option(Js.t({..}))=?,
    ~allowFontScaling: bool=?,
    ~theme: option(Paper_ThemeProvider.appTheme)=?,
    ~style: option(ReactNative.Style.t)=?,
    ~onLayout: option(unit => unit)=?,
    ~onLongPress: option(unit => unit)=?,
    ~onPress: option(unit => unit)=?,
    ~testID: option(string)=?,
    ~children: React.element
  ) =>
  React.element =
  "Text";
