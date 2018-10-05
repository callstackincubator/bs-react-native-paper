[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Button";

[@bs.deriving jsConverter]
type modes = [
  | [@bs.as "text"] `text
  | [@bs.as "outlined"] `outlined
  | [@bs.as "contained"] `contained
];

type jsIconProps = {
  .
  "size": int,
  "color": string,
  "direction": string,
};

type iconProps = {
  size: int,
  color: string,
  direction: string,
};

type renderIcon = jsIconProps => ReasonReact.reactElement;

let renderIcon =
    (reRenderIcon: iconProps => ReasonReact.reactElement): renderIcon =>
  (jsIconProps: jsIconProps) =>
    reRenderIcon({
      size: jsIconProps##size,
      color: jsIconProps##color,
      direction: jsIconProps##direction,
    });

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
  icon: renderIcon,
  [@bs.optional]
  color: string,
  [@bs.optional]
  accessibilityLabel: string,
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
      ~accessibilityLabel=?,
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
        ~accessibilityLabel?,
        ~style?,
        ~theme?,
        ~onPress,
        (),
      ),
    children,
  );
