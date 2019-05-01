[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~placeholder: string=?,
    ~value: string=?,
    ~icon: (Icon.jsIconType('a), 'a)=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~style: ReactNative.Style.t=?,
    ~onChangeText: string => unit=?,
    ~onIconPress: ReactNative.Event.pressEvent => unit=?
  ) =>
  React.element =
  "Searchbar";
