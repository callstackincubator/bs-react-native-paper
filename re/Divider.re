open Utils;

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
          "style": from_opt(style),
          "theme": from_opt(theme)
        }
      ),
    children
  );
