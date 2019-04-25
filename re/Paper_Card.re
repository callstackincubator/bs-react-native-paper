[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Card";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  elevation: int,
  [@bs.optional]
  onLongPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  onPress: ReactNative.Event.pressEvent => unit,
  [@bs.optional]
  style: ReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make =
    (~elevation=?, ~onLongPress=?, ~onPress=?, ~style=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~props=props(~elevation?, ~onLongPress?, ~onPress?, ~style?, ~theme?, ()),
    ~reactClass,
    children,
  );

module Actions = Paper_CardActions;
module Content = Paper_CardContent;
module Cover = Paper_CardCover;
