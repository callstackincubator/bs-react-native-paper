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
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  color: string,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  style: ReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  onPress: ReactNative.Event.pressEvent => unit,
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
      switch (icon) {
      | Some(Icon.Name(name)) =>
        props(
          ~mode=modesToJs(mode),
          ~disabled?,
          ~compact?,
          ~raised?,
          ~loading?,
          ~dark?,
          ~iconAsString=name,
          ~color?,
          ~accessibilityLabel?,
          ~style?,
          ~theme?,
          ~onPress,
          (),
        )
      | Some(Icon.Element(renderFunc)) =>
        props(
          ~mode=modesToJs(mode),
          ~disabled?,
          ~compact?,
          ~raised?,
          ~loading?,
          ~dark?,
          ~iconAsRenderFunc=renderFunc,
          ~color?,
          ~accessibilityLabel?,
          ~style?,
          ~theme?,
          ~onPress,
          (),
        )
      | None =>
        props(
          ~mode=modesToJs(mode),
          ~disabled?,
          ~compact?,
          ~raised?,
          ~loading?,
          ~dark?,
          ~color?,
          ~accessibilityLabel?,
          ~style?,
          ~theme?,
          ~onPress,
          (),
        )
      },
    children,
  );
