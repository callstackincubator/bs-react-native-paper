[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~inset: bool=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?
  ) =>
  React.element =
  "Divider";
