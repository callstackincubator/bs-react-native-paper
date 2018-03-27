[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Button";

let make =
    (
      ~disabled: bool=false,
      ~compact: bool=false,
      ~raised: bool=false,
      ~primary: bool=false,
      ~loading: bool=false,
      ~dark: bool=false,
      ~icon: option(ReasonReact.reactElement)=?,
      ~color: option(string)=?,
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
          "disabled": Js.Boolean.to_js_boolean(disabled),
          "compact": Js.Boolean.to_js_boolean(compact),
          "raised": Js.Boolean.to_js_boolean(raised),
          "primary": Js.Boolean.to_js_boolean(primary),
          "loading": Js.Boolean.to_js_boolean(loading),
          "dark": Js.Boolean.to_js_boolean(dark),
          "icon": Js.Undefined.fromOption(icon),
          "color": Js.Undefined.fromOption(color),
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme),
          "onPress": Js.Undefined.fromOption(onPress)
        }
      ),
    children
  );
