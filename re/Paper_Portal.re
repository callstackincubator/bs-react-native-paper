module Host = {
  [@bs.module "react-native-paper"] [@bs.scope "Portal"]
  external reactClass : ReasonReact.reactClass = "Host";

  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Portal";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make = (~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~theme?, ()),
    children,
  );
