[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Dialog";

let make =
  (
    ~dismissable: option(bool)=?,
    ~visible: option(bool),
    ~theme: option(Js.t({..}))=?,
    ~style: option(BsReactNative.Style.t)=?,
    ~onDismiss: option(unit => unit),
    children
  ) =>
ReasonReact.wrapJsForReason(
  ~reactClass,
  ~props=
    Js.Nullable.(
      {
        "dismissable": from_opt(dismissable),
        "visible": from_opt(visible),
        "style": from_opt(style),
        "theme": from_opt(theme),
        "onDismiss": from_opt(onDismiss)
      }
    ),
  children
);