[@bs.module "react-native-paper"]
external reactClass: ReasonReact.reactClass = "Chip";

[@bs.deriving jsConverter]
type modes = [ | [@bs.as "outlined"] `outlined | [@bs.as "flat"] `flat];

[@bs.deriving abstract]
type props = {
  [@bs.optional]
  mode: string,
  [@bs.optional]
  selected: bool,
  [@bs.optional]
  disabled: bool,
  [@bs.optional]
  accessibilityLabel: string,
  [@bs.optional]
  avatar: ReasonReact.reactElement,
  [@bs.optional] [@bs.as "icon"]
  iconAsString: string,
  [@bs.optional] [@bs.as "icon"]
  iconAsRenderFunc: Icon.renderIcon,
  [@bs.optional]
  style: BsReactNative.Style.t,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  onPress: BsReactNative.RNEvent.NativeEvent.t => unit,
  [@bs.optional]
  onClose: BsReactNative.RNEvent.NativeEvent.t => unit,
};

let make =
    (
      ~mode=`flat,
      ~selected=?,
      ~disabled=?,
      ~accessibilityLabel=?,
      ~avatar=?,
      ~icon=?,
      ~style=?,
      ~theme=?,
      ~onPress=?,
      ~onClose=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      switch (icon) {
      | Some(Icon.Name(name)) =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~iconAsString=name,
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      | Some(Icon.Element(renderFunc)) =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~iconAsRenderFunc=renderFunc,
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      | None =>
        props(
          ~mode=modesToJs(mode),
          ~selected?,
          ~disabled?,
          ~accessibilityLabel?,
          ~avatar?,
          ~style?,
          ~theme?,
          ~onPress?,
          ~onClose?,
          (),
        )
      },
    children,
  );
