[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Paragraph";

let make = (~style: option(ReactNative.Style.t)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Null_undefined.{"style": fromOption(style)},
    children,
  );
