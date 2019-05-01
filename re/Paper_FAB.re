[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~label: string=?,
    ~small: bool=?,
    ~color: string=?,
    ~disabled: bool=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
    ~accessibilityLabel: string=?,
    ~icon: (Icon.jsIconType('a), 'a)=?
  ) =>
  React.element =
  "FAB";
