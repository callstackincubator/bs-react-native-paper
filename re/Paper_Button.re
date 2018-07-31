[@bs.module "react-native-paper"]
external reactClass : ReasonReact.reactClass = "Button";

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  compact: bool,
  [@bs.optional]
  raised: bool,
  [@bs.optional]
  primary: bool,
  [@bs.optional]
  loading: bool,
  [@bs.optional]
  dark: bool,
  [@bs.optional]
  icon: ReasonReact.reactElement,
  [@bs.optional]
  color: string,
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.theme,
  onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~disabled=?,
      ~compact=?,
      ~raised=?,
      ~primary=?,
      ~loading=?,
      ~dark=?,
      ~icon=?,
      ~color=?,
      ~style=?,
      ~theme=?,
      ~onPress,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      props(
        ~disabled?,
        ~compact?,
        ~raised?,
        ~primary?,
        ~loading?,
        ~dark?,
        ~icon?,
        ~color?,
        ~style?,
        ~theme?,
        ~onPress,
        (),
      ),
    children,
  );
