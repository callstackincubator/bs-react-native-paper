[@bs.module "react-native-paper"] [@bs.scope "Card"]
external reactClass: ReasonReact.reactClass = "Actions";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  style: BsReactNative.Style.t,
};

let make = (~style=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~style?, ()),
    children,
  );
