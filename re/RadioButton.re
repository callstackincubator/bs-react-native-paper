

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "RadioButton";

let make =
    (
      ~checked: bool=false,
      ~disabled: bool=false,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "checked": Js.Boolean.to_js_boolean(checked),
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "onPress": from_opt(onPress),
          "color": from_opt(color),
          "theme": from_opt(theme)
        }
      ),
    children
  );
