[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Divider";

let make =
    (
      ~inset: bool=false,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "inset": Js.Boolean.to_js_boolean(inset),
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );
