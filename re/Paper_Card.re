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
      Js.Null_undefined.(
        {
          "style": from_opt(style),
          "elevation": from_opt(elevation),
          "theme": from_opt(theme),
          "onPress": from_opt(onPress)
        }
      ),
    children
  );
