[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Switch";

let make =
    (
      ~disabled: bool=false,
      ~value: bool=false,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onValueChange: option(bool => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "value": Js.Boolean.to_js_boolean(value),
          "color": Js.Undefined.fromOption(color),
          "onValueChange": Js.Undefined.fromOption(onValueChange),
          "theme": Js.Undefined.fromOption(theme),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );
