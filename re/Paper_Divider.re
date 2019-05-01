[@bs.module "react-native-paper"]
external make:
  (
    ~inset: bool=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?
  ) =>
  React.element =
  "Divider";
