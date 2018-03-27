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
      Js.Nullable.(
        {
          "dismissable": Js.Boolean.to_js_boolean(dismissable),
          "visible": Js.Boolean.to_js_boolean(visible),
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme),
          "onDismiss": Js.Undefined.fromOption(onDismiss)
        }
      ),
    children
  );
