[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "CardCover";

let make =
    (
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.({"style": from_opt(style), "theme": from_opt(theme)}),
    children
  );
