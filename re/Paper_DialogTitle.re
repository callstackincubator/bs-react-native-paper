

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "DialogTitle";

let make =
  (
    ~theme: option(Js.t({..}))=?,
    ~style: option(BsReactNative.Style.t)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "style": from_opt(style),
        "theme": from_opt(theme)
      }
    ),
  children
);
