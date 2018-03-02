open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "PaperProvider";

let make =
  (
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=Js.Obj.empty(),
  children
);
