[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "FAB";

let make =
    (
      ~small: bool=false,
      ~dark: bool=false,
      ~color: option(string)=?,
      ~theme: option(Js.t({..}))=?,
      ~icon: ReasonReact.reactElement,
      ~style: option(BsReactNative.Style.t)=?,
      ~onPress: option(BsReactNative.RNEvent.NativeEvent.t => unit)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      Js.Nullable.(
        {
          "small": Js.Boolean.to_js_boolean(small),
          "dark": Js.Boolean.to_js_boolean(dark),
          "color": Js.Undefined.fromOption(color),
          "icon": icon,
          "onPress": Js.Undefined.fromOption(onPress),
          "style": Js.Undefined.fromOption(style),
          "theme": Js.Undefined.fromOption(theme)
        }
      ),
    children
  );
