[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Banner";

type jsImageProps = {. "size": float};

type imageProps = {size: float};

type renderImage = jsImageProps => ReasonReact.reactElement;

let renderImage =
    (reRenderIcon: imageProps => ReasonReact.reactElement): renderImage =>
  (jsIconProps: jsImageProps) => reRenderIcon({size: jsIconProps##size});

[@bs.deriving abstract]
type action = {
  label: string,
  onPress: unit => unit,
};

[@bs.deriving abstract]
type props = {
  visible: bool,
  actions: array(action),
  [@bs.optional]
  image: renderImage,
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
};

let make = (~visible, ~actions, ~image=?, ~style=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=props(~visible, ~actions, ~image?, ~style?, ~theme?, ()),
    children,
  );
