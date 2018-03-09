

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "ToolbarBackAction";

let make =
    (
      ~dark: bool=false,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "dark": Js.Boolean.to_js_boolean(dark),
          "onPress": from_opt(onPress),
          "style": from_opt(style)
        }
      ),
    children
  );
