[@bs.module "react-native-paper"] [@react.component]
external make:
  (
    ~elevation: int=?,
    ~onLongPress: ReactNative.Event.pressEvent => unit=?,
    ~onPress: ReactNative.Event.pressEvent => unit=?,
    ~style: ReactNative.Style.t=?,
    ~theme: Paper_ThemeProvider.appTheme=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Card";

module Actions = Paper_CardActions;
module Content = Paper_CardContent;
module Cover = Paper_CardCover;
