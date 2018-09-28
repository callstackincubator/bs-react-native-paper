[@bs.module "react-native-paper"] [@bs.scope "Card"]
external reactClass: ReasonReact.reactClass = "Cover";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make = (~theme=?, ~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~style?, ~theme?, ()),
    children,
  );
