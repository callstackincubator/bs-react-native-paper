open Utils;

[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "TouchableRipple";

let make =
    (
      ~borderless: bool=false,
      ~background: option(Js.t({..}))=?,
      ~disabled: bool=false,
      ~rippleColor: option(string)=?,
      ~underlayColor: option(string)=?,
      ~style: option(BsReactNative.Style.t)=?,
      ~theme: option(Js.t({..}))=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "borderless": Js.Boolean.to_js_boolean(borderless),
          "background": from_opt(background),
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "rippleColor": from_opt(rippleColor),
          "underlayColor": from_opt(underlayColor),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress),
          "style": from_opt(style)
        }
      ),
    children
  );
