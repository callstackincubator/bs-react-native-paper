

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ThemeProvider";

let make =
  (
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=Js.Obj.empty(),
  children
);
