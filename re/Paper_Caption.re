[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Caption";

let make = (~style: option(BsReactNative.Style.t)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({"style": Js.Undefined.fromOption(style)}),
    children
  );
