[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~disabled: bool=?,
    ~value: bool=?,
    ~color: string=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?,
    ~onValueChange: bool => unit=?
  ) =>
  React.element =
  "Switch";
