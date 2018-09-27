[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Button";

[@bs.deriving jsConverter]
type modes = [
  | [@bs.as "text"] `text
  | [@bs.as "outlined"] `outlined
  | [@bs.as "contained"] `contained
];

[@bs.deriving abstract]
type props = {
  mode: string,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  compact: bool,
  [@bs.optional]
  raised: bool,
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
  theme: Paper_ThemeProvider.appTheme,
  onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~mode=`text,
      ~disabled=?,
      ~compact=?,
      ~raised=?,
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
        ~mode=modesToJs(mode),
        ~disabled?,
        ~compact?,
        ~raised?,
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
