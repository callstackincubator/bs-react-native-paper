[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Dialog";

let make =
    (
      ~dismissable: bool=false,
      ~visible: bool=false,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onDismiss: option(unit => unit),
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Null_undefined.(
        {
          "dismissable": Js.Boolean.to_js_boolean(dismissable),
          "visible": Js.Boolean.to_js_boolean(visible),
          "style": from_opt(style),
          "theme": from_opt(theme),
          "onDismiss": from_opt(onDismiss)
        }
      ),
    children
  );
