[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Checkbox";

let make =
    (
      ~checked: bool=false,
      ~theme: option(Js.t({..}))=?,
      ~disabled: bool=false,
      ~color: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "style": Js.Undefined.fromOption(style),
          "checked": Js.Boolean.to_js_boolean(checked),
          "theme": Js.Undefined.fromOption(theme),
          "onPress": Js.Undefined.fromOption(onPress),
          "color": Js.Undefined.fromOption(color),
          "disabled": Js.Boolean.to_js_boolean(disabled)
        }
      ),
    children
  );
