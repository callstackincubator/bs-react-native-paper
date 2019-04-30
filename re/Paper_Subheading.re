[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Subheading";

let make = (~style: option(ReactNative.Style.t)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Null_undefined.{"style": fromOption(style)},
    children,
  );
