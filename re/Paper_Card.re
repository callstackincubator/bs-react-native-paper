[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Card";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  elevation: int,
  [@bs.optional]
  onLongPress: BsReactNative.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  style: BsReactNative.Style.t,
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
