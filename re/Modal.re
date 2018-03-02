open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Modal";

let make =
    (
      ~dismissable: bool=false,
      ~visible: bool=false,
      ~onDismiss: option(unit => unit),
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dismissable": Js.Boolean.to_js_boolean(dismissable),
          "visible": Js.Boolean.to_js_boolean(visible),
          "onDismiss": from_opt(onDismiss)
        }
      ),
    children
  );
