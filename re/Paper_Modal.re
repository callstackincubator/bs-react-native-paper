[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Modal";

let make =
    (
      ~dismissable: bool=false,
      ~visible: bool=false,
      ~onDismiss: option(unit => unit),
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "dismissable": dismissable,
          "visible": visible,
          "onDismiss": fromOption(onDismiss),
        }
      ),
    children,
  );
