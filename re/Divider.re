[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Divider";

let make =
  (
    ~inset: option(bool)=?,
    ~theme: option(Js.t({..}))=?,
    ~style: option(BsReactNative.Style.t)=?,
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "inset": from_opt(inset),
        "style": from_opt(style),
        "theme": from_opt(theme)
      }
    ),
  children
);