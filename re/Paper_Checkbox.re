[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Checkbox";

[@bs.deriving abstract]
type props = {
  checked: bool,
  [@bs.optional] [@bs.optional]
  theme: Paper_ThemeProvider.theme,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  color: string,
  [@bs.optional]
  style: BsReactNative.Style.t,
  onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~checked=false,
      ~theme=?,
      ~disabled=?,
      ~color=?,
      ~style=?,
      ~onPress,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(~checked, ~theme?, ~disabled?, ~color?, ~style?, ~onPress, ()),
    children,
  );
