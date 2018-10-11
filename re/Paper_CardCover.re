module type ImageComponent = {
  type imageURISource;
  let imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [ | `default | `reload | `forceCache | `onlyIfCached]=?,
      ~scale: float=?,
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    imageURISource;
  type imageSource =
    | URI(imageURISource)
    | Required(BsReactNative.Packager.required)
    | Multiple(list(imageURISource));
  type defaultURISource;
  let defaultURISource:
    (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) =>
    defaultURISource;
  type defaultSource =
    | URI(defaultURISource)
    | Required(BsReactNative.Packager.required);
  module Event: {
    type error;
    type progress = {
      loaded: float,
      total: float,
    };
  };
  let make:
    (
      ~onError: Event.error => unit=?,
      ~onLayout: BsReactNative.RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLoad: unit => unit=?,
      ~onLoadEnd: unit => unit=?,
      ~onLoadStart: unit => unit=?,
      ~resizeMode: [< | `center | `contain | `cover | `repeat | `stretch]=?,
      ~source: imageSource=?,
      ~style: BsReactNative.Style.t=?,
      ~testID: string=?,
      ~resizeMethod: [< | `auto | `resize | `scale]=?,
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~blurRadius: float=?,
      ~capInsets: BsReactNative.Types.insets=?,
      ~defaultSource: defaultSource=?,
      ~onPartialLoad: unit => unit=?,
      ~onProgress: Event.progress => unit=?,
      ~theme: Paper_ThemeProvider.appTheme=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: BsReactNative.View.Impl) : ImageComponent => {
  type imageURISource;
  [@bs.obj]
  external imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [@bs.string] [
                | `default
                | `reload
                | [@bs.as "force-cache"] `forceCache
                | [@bs.as "only-if-cached"] `onlyIfCached
              ]
                =?,
      ~scale: float=?,
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    imageURISource =
    "";
  type imageSource =
    | URI(imageURISource)
    | Required(BsReactNative.Packager.required)
    | Multiple(list(imageURISource));
  type defaultURISource;
  [@bs.obj]
  external defaultURISource:
    (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) =>
    defaultURISource =
    "";
  type defaultSource =
    | URI(defaultURISource)
    | Required(BsReactNative.Packager.required);
  type rawImageSourceJS;
  external rawImageSourceJS: 'a => rawImageSourceJS = "%identity";
  module Event = {
    type t;
    type error;
    type progress = {
      loaded: float,
      total: float,
    };
    [@bs.get] external progress: t => progress = "nativeEvent";
  };
  let encodeResizeMode = x =>
    switch (x) {
    | `cover => "cover"
    | `contain => "contain"
    | `stretch => "stretch"
    | `repeat => "repeat"
    | `center => "center"
    };
  let encodeSource = (x: imageSource) =>
    switch (x) {
    | URI(x) => rawImageSourceJS(x)
    | Required(x) => rawImageSourceJS(x)
    | Multiple(x) => rawImageSourceJS(Array.of_list(x))
    };
  let encodeResizeMethod = x =>
    switch (x) {
    | `auto => "auto"
    | `resize => "resize"
    | `scale => "scale"
    };
  let encodeDefaultSource = (x: defaultSource) =>
    switch (x) {
    | URI(x) => rawImageSourceJS(x)
    | Required(x) => rawImageSourceJS(x)
    };
  let make =
      (
        ~onError=?,
        ~onLayout=?,
        ~onLoad=?,
        ~onLoadEnd=?,
        ~onLoadStart=?,
        ~resizeMode=?,
        ~source=?,
        ~style=?,
        ~testID=?,
        ~resizeMethod=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~blurRadius=?,
        ~capInsets=?,
        ~defaultSource=?,
        ~onPartialLoad=?,
        ~onProgress=?,
        ~theme=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Js.Undefined.{
          "onLayout": fromOption(onLayout),
          "onError": fromOption(onError),
          "onLoad": fromOption(onLoad),
          "onLoadEnd": fromOption(onLoadEnd),
          "onLoadStart": fromOption(onLoadStart),
          "resizeMode":
            fromOption(UtilsRN.option_map(encodeResizeMode, resizeMode)),
          "source": fromOption(UtilsRN.option_map(encodeSource, source)),
          "style": fromOption(style),
          "testID": fromOption(testID),
          "resizeMethod":
            fromOption(UtilsRN.option_map(encodeResizeMethod, resizeMethod)),
          "accessibilityLabel": fromOption(accessibilityLabel),
          "accessible":
            fromOption(UtilsRN.optBoolToOptJsBoolean(accessible)),
          "blurRadius": fromOption(blurRadius),
          "capInsets": fromOption(capInsets),
          "defaultSource":
            fromOption(
              UtilsRN.option_map(encodeDefaultSource, defaultSource),
            ),
          "onPartialLoad": fromOption(onPartialLoad),
          "onProgress":
            fromOption(
              UtilsRN.option_map(
                (x, y) => x(Event.progress(y)),
                onProgress,
              ),
            ),
          "theme": fromOption(theme),
        },
    );
};

include CreateComponent({
  [@bs.module "react-native-paper"] [@bs.scope "Card"]
  external view: ReasonReact.reactClass = "Cover";
});
