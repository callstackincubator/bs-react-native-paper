[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Modal";

let make =
  (
    ~dismissable: option(bool)=?,
    ~visible: option(bool),
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
        "onDismiss": from_opt(onDismiss)
      }
    ),
  children
);