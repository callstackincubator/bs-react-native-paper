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
          "background": Js.Undefined.fromOption(background),
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "rippleColor": Js.Undefined.fromOption(rippleColor),
          "underlayColor": Js.Undefined.fromOption(underlayColor),
          "theme": Js.Undefined.fromOption(theme),
          "onPress": Js.Undefined.fromOption(onPress),
          "style": Js.Undefined.fromOption(style)
        }
      ),
    children
  );
