open Utils;

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
          "style": from_opt(style),
          "checked": Js.Boolean.to_js_boolean(checked),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress),
          "color": from_opt(color),
          "disabled": Js.Boolean.to_js_boolean(disabled)
        }
      ),
    children
  );
