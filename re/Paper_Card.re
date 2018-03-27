[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Card";

let make =
    (
      ~elevation: option(int)=?,
      ~theme: option(Js.t({..}))=?,
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
          "elevation": Js.Undefined.fromOption(elevation),
          "theme": Js.Undefined.fromOption(theme),
          "onPress": Js.Undefined.fromOption(onPress)
        }
      ),
    children
  );
