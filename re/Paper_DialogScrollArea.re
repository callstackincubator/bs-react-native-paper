[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DialogScrollArea";

let make = (~style: option(Rebolt.Style.t)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Null_undefined.({"style": fromOption(style)}),
    children,
  );
